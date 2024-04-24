import tensorflow as tf
import logging

tf.get_logger().setLevel(logging.ERROR)


def get_mnist_dataset():
    (X_train, y_train), (X_test, y_test) = tf.keras.datasets.mnist.load_data()
    X_train, X_test = X_train / 255., X_test / 255.
    
    return (X_train, y_train), (X_test, y_test)


def get_rnn_model(timesteps, input_dim):
    model = tf.keras.models.Sequential([
        tf.keras.layers.Input((timesteps, input_dim)),
        tf.keras.layers.SimpleRNN(32),
        tf.keras.layers.Dense(10, activation='softmax')
    ], name = 'RNN')

    model.compile(
        optimizer = tf.keras.optimizers.Adam(),
        loss = tf.keras.losses.SparseCategoricalCrossentropy(),
        metrics = ['accuracy']
    )
    
    return model


def main():
    (X_train, y_train), (X_test, y_test) = get_mnist_dataset()
    
    print(f'X_train: {X_train.shape}')
    print(f'Y_train: {y_train.shape}')
    print(f'X_test : {X_test.shape}')
    print(f'Y_test : {y_test.shape}\n')
    
    timesteps, input_dim = X_train.shape[1:]
    BATCH_SIZE = 128
    EPOCHS = 5
    
    model = get_rnn_model(timesteps, input_dim)
    print(model.summary())
    
    print('\nTraining RNN\n')
    model.fit(X_train, y_train, batch_size=BATCH_SIZE, epochs=EPOCHS, validation_split=0.2)
    
    print(f'\nPerformance on test set: {model.evaluate(X_test, y_test, verbose=0)}')


if __name__ == '__main__':
    main()
