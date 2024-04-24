import tensorflow as tf
import logging

tf.get_logger().setLevel(logging.ERROR)


def get_cifar_dataset():
    (X_train, y_train), (X_test, y_test) = tf.keras.datasets.cifar10.load_data()
    X_train, X_test = X_train / 255., X_test / 255.
    
    return (X_train, y_train), (X_test, y_test)


def get_cnn_model(input_shape):
    model = tf.keras.models.Sequential([
        tf.keras.layers.Input(input_shape),
        tf.keras.layers.Conv2D(filters=32, kernel_size=(3, 3), activation='relu'),
        tf.keras.layers.MaxPooling2D(),
        tf.keras.layers.Conv2D(filters=64, kernel_size=(3, 3), activation='relu'),
        tf.keras.layers.MaxPooling2D(),
        tf.keras.layers.Conv2D(filters=64, kernel_size=(3, 3), activation='relu'),
        tf.keras.layers.MaxPooling2D(),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dense(64, activation='relu'),
        tf.keras.layers.Dense(10, activation='softmax'),
    ], name = 'CNN')

    model.compile(
        optimizer = tf.keras.optimizers.Adam(),
        metrics = ['accuracy'],
        loss = tf.keras.losses.SparseCategoricalCrossentropy()
    )
    
    return model


def main():
    (X_train, y_train), (X_test, y_test) = get_cifar_dataset()
    
    print(f'X_train: {X_train.shape}')
    print(f'Y_train: {y_train.shape}')
    print(f'X_test : {X_test.shape}')
    print(f'Y_test : {y_test.shape}\n')
    
    BATCH_SIZE = 64
    EPOCHS = 10
    
    model = get_cnn_model(X_train.shape[1:])
    print(model.summary())
    
    print('\nTraining CNN\n')
    model.fit(X_train, y_train, batch_size=BATCH_SIZE, epochs=EPOCHS)
    
    print(f'\nPerformance on test set: {model.evaluate(X_test, y_test, verbose=0)}')


if __name__ == '__main__':
    main()
