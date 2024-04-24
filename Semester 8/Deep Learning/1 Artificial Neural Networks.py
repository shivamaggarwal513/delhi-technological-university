import tensorflow as tf
import logging

tf.get_logger().setLevel(logging.ERROR)


def normalize_images(X):
    return tf.cast(X, tf.float32) / 255.


def get_mnist_dataset():
    (X_train, y_train), (X_test, y_test) = tf.keras.datasets.mnist.load_data()
    
    X_train = normalize_images(X_train)
    X_test = normalize_images(X_test)
    
    return (X_train, y_train), (X_test, y_test)


def get_ann_model(input_shape):
    model = tf.keras.Sequential([
        tf.keras.Input(input_shape),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dense(200, 'relu'),
        tf.keras.layers.Dense(100, 'relu'),
        tf.keras.layers.Dense(50, 'relu'),
        tf.keras.layers.Dense(25, 'relu'),
        tf.keras.layers.Dense(10)
    ], name = 'ANN')

    model.compile(
        optimizer = tf.keras.optimizers.Adam(),
        loss = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True)
    )
    
    return model


def main():
    (X_train, y_train), (X_test, y_test) = get_mnist_dataset()
    
    print(f'X_train: {X_train.shape}')
    print(f'Y_train: {y_train.shape}')
    print(f'X_test : {X_test.shape}')
    print(f'Y_test : {y_test.shape}\n')
    
    BATCH_SIZE = 64
    EPOCHS = 5
    
    model = get_ann_model(X_train.shape[1:])
    print(model.summary())
    
    print('\nTraining ANN\n')
    model.fit(X_train, y_train, batch_size=BATCH_SIZE, epochs=EPOCHS)
    
    print(f'\nLoss on test set: {model.evaluate(X_test, y_test, verbose=0)}')


if __name__ == '__main__':
    main()
